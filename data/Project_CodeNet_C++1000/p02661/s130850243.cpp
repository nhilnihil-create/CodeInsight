#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n,a,b,med1,med2;
    vector<ll>V1,V2;
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> a >> b;
        V1.push_back(a);
        V2.push_back(b);
    }
    sort(V1.begin(),V1.end());
    sort(V2.begin(),V2.end());
    if (n%2==1) {
        med1=V1[n/2];
        med2=V2[n/2];
        cout << med2-med1+1;
    }
    else {
        med1=(V1[n/2-1]+V1[n/2]);
        med2=(V2[n/2-1]+V2[n/2]);
        cout << med2-med1+1;
    }
}
