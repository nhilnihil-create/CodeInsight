#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define all_acc(x) (x).begin(),(x).end(),0LL
#define int long long
#define absSort(v) sort(a.begin(), a.end(), [](int i, int j) -> bool {return abs(i) < abs(j);});
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

//出力するよ
void output(vector<int> s,int index){
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i!=0) cout<<" ";
        if(i==index) cout<<"["<<s[i]<<"]";
        else cout<<s[i];//<<endl;
    }
    cout<<endl;
}

int partition(vector<int> &a,int p,int r){
    int x=a[r-1];
    int i=p-1;
    for(int j=p;j<(r-1);j++){
        if(a[j]<=x){
            i++;
            int key=a[i];
            a[i]=a[j];
            a[j]=key;
        }
    }
    int key=a[i+1];
    a[i+1]=a[r-1];
    a[r-1]=key;
    return i+1;
}

signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int index=partition(a,0,n);
    output(a,index);
}
