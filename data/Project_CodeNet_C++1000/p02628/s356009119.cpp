#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;

int L[200000],R[200000];

void merge(int A[],int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;
    for(int i=0;i<n1;i++) L[i]=A[left+i];
    for(int i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1] =R[n2]=INFTY;
    int i=0,j=0;
    for(int p=left;p<right;p++){
        if(L[i]<=R[j]) A[p]=L[i++];
        else A[p]=R[j++];
    }
}

void sort(int A[],int left,int right){
    if(left+1<right){
        int mid=(left + right)/2;
        sort(A,left,mid);
        sort(A,mid,right);
        merge(A,left,mid,right);
    }
}

//sort(A,0,n)で使用
int main(){
    int n,k,ans=0;
    int A[1005];
    cin>>n>>k;
    REP(i,n) cin>>A[i];
    sort(A,0,n);
    REP(i,k) ans+=A[i];
    cout<<ans<<endl;
}