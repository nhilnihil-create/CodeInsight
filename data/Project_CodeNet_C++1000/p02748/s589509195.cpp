#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,m;
    cin >> a >> b >> m;
    vector <int> priceA(a),priceB(b),x(m),y(m),c(m);
    int niceA = -1,niceB = -1;
    int minA = -1, minB = -1;
    for(int i = 0; i < a; i++){
        cin >> priceA[i];
        if(i==0){
            minA = priceA[i];
            niceA = i;
        }else{
            if(minA>priceA[i]){
                minA = priceA[i];
                niceA = i;
            }
        }
    }
    for(int i = 0; i < b; i++){
        cin >> priceB[i];
        if(i==0){
            minB = priceB[i];
            niceB = i;
        }else{
            if(minB>priceB[i]){
                minB = priceB[i];
                niceB = i;
            }
        }
    }
    vector <int> couponedPrice(m);
    int ans = -1;
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i] >> c[i];
        couponedPrice[i]=priceA[x[i]-1]+priceB[y[i]-1]-c[i];
        //cout << "couponed price " << couponedPrice[i] << endl;
        if(i==0){
            ans=couponedPrice[i];
        }else{
            ans=min(ans,couponedPrice[i]);
        }
    }
    ans=min(ans,priceA[niceA]+priceB[niceB]);
    cout << ans << endl;

    return 0;
}