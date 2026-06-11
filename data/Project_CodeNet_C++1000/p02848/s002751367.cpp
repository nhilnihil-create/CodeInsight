#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef set<int> si;
typedef set<string> ss;
typedef map<int,int> mii;
typedef map<string,int>msi;
typedef map<string,string>mss;
void solve(){
    string inp,res="";
    int n;
    cin>>n;
    cin>>inp;
    for(int i=0;i<inp.size();i++){
        char ch = inp[i];
        ch+=n;
        if(ch>'Z'){
            ch-=26;
        }
        res+=ch;
    }
    cout<<res<<endl;
}
int main(){
    int t;
    t=1;
    while(t--){
       solve();
    }
    return 0;
}
