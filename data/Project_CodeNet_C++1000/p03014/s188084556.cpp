#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> wall_y(h);
    vector<vector<int>> wall_t(w);
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            char c;
            cin >> c;
            if(c == '#'){
                wall_y.at(i).push_back(j);
                wall_t.at(j).push_back(i);
            }
        }
    }
    vector<vector<int>> yoko(h, vector<int>(w,0));
    vector<vector<int>> tate(h, vector<int>(w,0));
    for(int i=0; i<h; i++){
        if(wall_y.at(i).size() == 0){
            for(int j=0; j<w; j++){
                yoko.at(i).at(j) = w;
            }
        }
        else if(wall_y.at(i).size() == 1){
            int k = wall_y.at(i).at(0);
            for(int j=0; j<w; j++){
                if(j < k) yoko.at(i).at(j) = k;
                else if(j==k) yoko.at(i).at(j) = 0;
                else yoko.at(i).at(j) = w-k-1;
            }
        }
        else{
            int s = wall_y.at(i).size();
            int first,end;
            first = wall_y.at(i).at(0);
            end = wall_y.at(i).at(s-1);
            for(int j=0; j<first; j++){
                yoko.at(i).at(j) = first;
            }
            for(int j=end+1; j<w; j++){
                yoko.at(i).at(j) = w-end-1;
            }
            for(int j=0; j<=s-2;j++){
                int p,q;
                p = wall_y.at(i).at(j);
                q = wall_y.at(i).at(j+1);
                for(int l=p+1; l<q; l++){
                    yoko.at(i).at(l) = q-p-1;
                }
            }
        }
    }

    for(int i=0; i<w; i++){
        if(wall_t.at(i).size() == 0){
            for(int j=0; j<h; j++){
                tate.at(j).at(i) = h;
            }
        }
        else if(wall_t.at(i).size() == 1){
            int k = wall_t.at(i).at(0);
            for(int j=0; j<h; j++){
                if(j < k) tate.at(j).at(i) = k;
                else if(j==k) tate.at(j).at(i) = 0;
                else tate.at(j).at(i) = h-k-1;
            }
        }
        else{
            int s = wall_t.at(i).size();
            int first,end;
            first = wall_t.at(i).at(0);
            end = wall_t.at(i).at(s-1);
            for(int j=0; j<first; j++){
                tate.at(j).at(i) = first;
            }
            for(int j=end+1; j<h; j++){
                tate.at(j).at(i) = h-end-1;
            }
            for(int j=0; j<=s-2;j++){
                int p,q;
                p = wall_t.at(i).at(j);
                q = wall_t.at(i).at(j+1);
                for(int l=p+1; l<q; l++){
                    tate.at(l).at(i) = q-p-1;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            ll light = tate.at(i).at(j) + yoko.at(i).at(j) -1;
            ans = max(ans, light);
        }
    }
    cout << ans << endl;
}
