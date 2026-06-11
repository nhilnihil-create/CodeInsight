/*
      author : Nishikawa
      created: 06.08.2020 22:22:11
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int x;
    int n;
    cin >> x >> n;
    vector<int> p(n+1);
    vector<int> q(201,1);
    for(int i=1; i<=n; i++) cin >> p[i];
    for(int i=1; i<=n; i++) q[p[i]]=0;

    int cnt=1;
    int y = x;
    while(1){
        if(cnt&1){
            if(q[x]!=0 || x<0){
                cout << x << endl;
                return 0;
            }
            x--;
        }
        else{
            if(q[y]){
                cout << y << endl;
                return 0;
            }
            y++;
        }
        cnt++;
    }
    cout << x << endl;
    return 0;
}