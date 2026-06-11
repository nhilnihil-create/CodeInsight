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
    for(auto isi:s){
        if(isi=='?') cout<<"D";
        else cout<<isi;
    }
    cout<<endl;
}