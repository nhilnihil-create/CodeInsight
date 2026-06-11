#include<iostream>
#include<math.h>
#include<string>
#include<vector>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
int main(){
    int i;
    int max=0;
    int k,n;
    cin>>k>>n;
    vector <int> a;
    rep(i,n){
        int t;
        cin>>t;
        a.push_back(t);
    }
    rep(i,n-1){
        int temp=a[i+1]-a[i];
        if(max<temp){
            max=temp;
        }
    }
    if(((k-a[n-1])+a[0])>max){
        cout<<k-((k-a[n-1])+a[0])<<endl;
        return 0;
    }else{
        cout<<k-max;
    }
}
