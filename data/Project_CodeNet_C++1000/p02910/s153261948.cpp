# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    int cnt=1;
    for(int i=0;i<s.size();i++){
        if(cnt&1){
            if(s[i]=='L'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        else{
            if(s[i]=='R'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cnt++;
    }
    cout<<"Yes"<<endl;
}