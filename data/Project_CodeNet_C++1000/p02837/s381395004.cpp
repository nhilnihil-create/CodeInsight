#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<pair<int, bool>> testimony[20];
bool honest[20];
int ans = 0;

void backtrack(int cur, int n){

    if(cur > n){

        bool valid = true;
        int cnt_of_honest = 0;
        
        for(int i = 1; i<=n; i++){

            if(honest[i]){
                cnt_of_honest++;
                for(auto p : testimony[i]){
                    /// p.first -> p.second
                    if(honest[p.first] != p.second){
                        valid = false;
                    }
                }
            }

        }


        if(valid == true){
            /// I have found cnt_of_honest;
            ans = max(ans, cnt_of_honest);
        }



        return;
    }


    honest[cur] = true;
    backtrack(cur+1, n);


    honest[cur] = false;
    backtrack(cur+1, n);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;

    for(int i = 1; i<=n; i++){
        int k;
        cin>>k;
        for(int j = 0; j<k; j++){
            int x, y;
            cin>>x>>y;
            bool z;
            if(y == 1)
                z = true;
            else
                z = false;

            pair<int, bool> p = make_pair(x, z);
            testimony[i].push_back(p);
        }
    }

    backtrack(1, n);


    cout<<ans<<endl;

    return 0;
}

