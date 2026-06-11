#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int m1;
    rep(i,n){
        cin>>a[i];
        m1=max(m1,a[i]);
    }

    int m2=0;
    int cnt=0;
    rep(i,n){
        if(a[i]==m1)++cnt;
        else m2=max(m2,a[i]);
    }

    rep(i,n){
        if(a[i]!=m1){
            cout<<m1<<endl;
        }else if(cnt>1){
            cout<<m1<<endl;
        }else{
            cout<<m2<<endl;
        }
    }

}