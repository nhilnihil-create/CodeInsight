#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define all_acc(x) (x).begin(),(x).end(),0LL
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

int accumulate(int* a,int n){
    return accumulate(a,a+n,0LL);
}

int accumulate(vector<int> a){
    return accumulate(a.begin(),a.end(),0LL);
}

signed main(){ 
    int n; cin>>n;
    int a[n],s[n];
    for(int i=0;i<n;i++){
        int ai; cin>>ai;
        if(i==0) {
            s[i]=ai;
            a[i]=ai;
        }
        else{
            s[i]=ai+s[i-1];
            a[i]=ai;
        }
    }

    int sum=accumulate(a,a+n,0LL);
    int mergin=sum+1;
    int pred=0;

    for(int i=0;i<n;i++){
        pred+=a[i];
        if(abs(pred-(sum-pred))<mergin){
            mergin=abs(pred-(sum-pred));
        }else{
            break;
        }
    }

    cout<<mergin<<endl;

}  