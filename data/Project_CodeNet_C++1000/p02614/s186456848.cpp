#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
const int N=1e5+5,mod=1e9+7;
typedef long long ll;
int n,m,k;
string s[10];
char arr[10][10];
set<string>se;
void solve(){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<(1<<m);j++){
            for(int r=0;r<n;r++){
                for(int c=0;c<m;c++){
                    arr[r][c]=s[r][c];
                }

            }
            for(int r=0;r<n;r++){
                if((1<<r)&i){
                    for(int c=0;c<m;c++)arr[r][c]='R';
                }
            }
            for(int c=0;c<m;c++){
                if((1<<c)&j){
                    for(int r=0;r<n;r++)arr[r][c]='R';
                }
            }
            int cnt=0;
            string ans="";
            for(int r=0;r<n;r++){
                for(int c=0;c<m;c++){
                    if(arr[r][c]=='#')cnt++;
                    ans+=arr[r][c];
                }

            }
            if(cnt==k){
                se.insert(ans);
            }

        }
    }
}
int main()
{
    Elhabashy
    input();
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>s[i];
    solve();
    cout<<se.size()<<endl;

}
