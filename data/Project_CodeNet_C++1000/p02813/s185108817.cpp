#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> ps(n);
    vector<int> qs(n);
    vector<int> check(n);
    for(int i = 0; i < n; i++){
        cin >> ps[i];
        check[i] = ps[i];
    }
    for(int i = 0; i < n; i++){
        cin >> qs[i];
    }
    
    sort(check.begin(), check.end());
    
    int p_num = 0;
    int q_num = 0;
    int num = 1;
    do{
        bool p_flag = true;
        for(int i = 0; i < n; i++){
            if(ps[i] != check[i]){
                p_flag = false;
                break;
            }
        }
        if(p_flag){
            p_num = num;
        }
        bool q_flag = true;
        for(int i = 0; i < n; i++){
            if(qs[i] != check[i]){
                q_flag = false;
                break;
            }
        }
        if(q_flag){
            q_num = num;
        }
        num++;
    }while(next_permutation(check.begin(), check.end()));
    
    cout << abs(p_num - q_num) << endl;
    
}