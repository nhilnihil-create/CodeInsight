#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> kitai(n),dp(n-k+1);
    double ans=0;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        kitai.at(i)=(a+1);
    }
    for(int i=0;i<k;i++){
        dp.at(0)+=kitai.at(i);
    }
    ans=dp.at(0);
    if(n-k+1!=1){
        for(int i=1;i<n-k+1;i++){
            dp.at(i)=dp.at(i-1)+kitai.at(i+k-1)-kitai.at(i-1);
            if(ans<dp.at(i))ans=dp.at(i);
        }
    }
    double ansss=(double)ans/(double)2;
    printf("%.10f\n",ansss);
    return 0;
}
