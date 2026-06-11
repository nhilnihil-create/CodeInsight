# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d;
    cin>>s;
    int cnt=0;
    for(int i=a;i<=c;i++){
        if(s[i-1]=='#') cnt++;
        else cnt=0;
        if(cnt==2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cnt=0;
    for(int i=b;i<=d;i++){
        if(s[i-1]=='#') cnt++;
        else cnt=0;
        if(cnt==2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    if(c<d){
        cout<<"Yes"<<endl;
        return 0;
    }
    else{
        for(int i=b-1;i<=(d-1);i++){
            if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;

}