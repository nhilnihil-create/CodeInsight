#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,k;
    cin >> n >> k;
    vector <int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    vector <long double> expValSum(n);
    for(long i = 0; i < n; i++){
        if(i==0){
            expValSum[i]=((long double)1+(long double)p[i])*(long double)p[i]/(long double)2;;
            expValSum[i]/=(long double)p[i];
        }else{
            long double value = ((long double)1+(long double)p[i])*(long double)p[i]/(long double)2;
            expValSum[i]=value/(long double)p[i];
            expValSum[i]+=expValSum[i-1];
        }
    }
    #if 0
    for(long i = 0; i < n; i++){
        cout << expValSum[i] << " ";
    }
    cout << endl;
    #endif
    long double ans = 0;
    for(long i = 0; i < n; i++){
        if(k==1){
            if(i==0){
                long double tmp = expValSum[i];
                //cout << tmp << " ";
                if(tmp>ans){
                    ans = tmp;
                }
            }else{
                long double tmp = expValSum[i]-expValSum[i-1];
                //cout << tmp << " ";
                if(tmp>ans){
                    ans = tmp;
                }
            }
        }else{
            if((i-k)>=0){
                long double tmp = expValSum[i]-expValSum[i-k];
                //cout << tmp << " ";
                if(tmp>ans){
                    ans = tmp;
                }
            }else if(i==k-1){
                long double tmp = expValSum[i];
                //cout << tmp << " ";
                if(tmp>ans){
                    ans = tmp;
                }
            }
        }
    }
    //cout << endl;
    cout << std::fixed << std::setprecision(13) << ans << endl;

    return 0;
}