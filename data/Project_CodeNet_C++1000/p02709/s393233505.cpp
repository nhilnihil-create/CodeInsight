#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    struct map{
        int index;
        int64_t elem;
    };
    vector<map> A;
    
    cin >> N;
    for(int i=0;i<N;i++){
        int64_t elem;
        cin >> elem;
        A.push_back({i,elem});
    };

    sort(A.begin(), A.end(), [](const map& x, const map& y){ return x.elem > y.elem;});

    struct x_y{
        int x;
        int y;
    };
    vector<x_y> dpnxy;
    vector<x_y> dpnxy1;
    dpnxy.push_back({0,0});

    vector<int64_t> dpn;
    vector<int64_t> dpn1;
    dpn.push_back(0);

    for(int n=1;n<=N;n++){
        for(int i=0;i<dpnxy.size();i++){
            int x = dpnxy.at(i).x;
            int y = dpnxy.at(i).y;
            int n_left = x;
            int n_right = N-1-y;

            if(A.at(n-1).index >= n_left){
                int64_t l = dpn.at(i) + A.at(n-1).elem * (A.at(n-1).index - n_left);
                
                if(i != 0 && dpnxy1.at(dpnxy1.size()-1).x == x+1 && dpnxy1.at(dpnxy1.size()-1).y ==y){
                    if(dpn1.at(dpn1.size()-1) < l){
                        dpn1.at(dpn1.size()-1) = l;
                    }
                }else{
                    dpnxy1.push_back({x+1,y});
                    dpn1.push_back(l);
                }
            }

            if(A.at(n-1).index <= n_right){
                int64_t r = dpn.at(i) + A.at(n-1).elem * (n_right - A.at(n-1).index);
                dpnxy1.push_back({x,y+1});
                dpn1.push_back(r);
            }
        }
        dpnxy = dpnxy1;
        dpn = dpn1;
        // for(int i=0;i<dpn.size();i++){
        //     cout << dpnxy.at(i).x << " " << dpnxy.at(i).y << " " << dpn.at(i) << "|";
        // }
        // cout << endl;
        dpnxy1.clear();
        dpn1.clear();
    }
    int64_t result = 0;
    for(int i=0;i<dpn.size();i++){
        if(result < dpn.at(i)){
            result = dpn.at(i);
        }
    }
    cout << result << endl;
}