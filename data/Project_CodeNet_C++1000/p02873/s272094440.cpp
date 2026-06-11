# include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
typedef long long ll;
string s;
ll ans;
int kiri[500005],kanan[500005];
int arr[500005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    memset(kiri,-1,sizeof(kiri));
    memset(kanan,-1,sizeof(kanan));
    for(int i=0;i<s.size();i++){
        if(s[i]=='<') {
            if(i!=0 && kiri[i-1]!=-1){
                kiri[i]=kiri[i-1]+1;
            }
            else kiri[i]=0;
        }
        
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='>') {
            if(kanan[i+1]!=-1){
                kanan[i]=kanan[i+1]+1;
            }
            else kanan[i]=1;
        }
        
    }
    for(int i=0;i<s.size();i++){
        if(i!=0 && kiri[i-1]!=-1 && kanan[i]!=-1){
            arr[i]=max(kiri[i-1]+1,kanan[i]);
        } 
        else if(kiri[i]!=-1) arr[i]+=kiri[i];
        else if(kanan[i]!=-1)arr[i] += kanan[i];
    }
    for(int i=0;i<=s.size()-1;i++){
        ans+=arr[i];
    }
    if(s.back()=='>') ans+=0;
    else ans+=kiri[s.size()-1]+1;
    cout<<ans<<endl;
}




