#include<iostream>
#include<cmath>

using namespace std;
typedef long long LL;
const int N=110;
int n;
int l[N];

bool judge(int a,int b,int c){
    if(a==b) return false;
    if(b==c) return false;
    if(a==c) return false;
    if((LL)a+b<=c) return false;
    if((LL)b+c<=a) return false;
    if((LL)a+c<=b) return false;
    return true;
}

int main(){
    cin>>n;
    for(int i=0;i<n;++i) cin>>l[i];
    int cnt=0;
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            for(int k=j+1;k<n;++k){
                if(judge(l[i],l[j],l[k])){
                    //cout<<i<<" "<<j<<" "<<k<<" "<<cnt<<endl;
                    cnt++;
                }
            }
    
    cout<<cnt<<endl;
    return 0;
}