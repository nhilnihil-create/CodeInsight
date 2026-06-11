#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,m;
    cin >> a >> b >> m;
    vector<int> veca(a);
    vector<int> vecb(b);
    for(int i=0;i<a;i++){
        cin >> veca[i];
    }
    for(int i=0;i<b;i++){
        cin >> vecb[i];
    }
    vector<int> x(m);
    vector<int> y(m);
    vector<int> c(m);
    int mn;
    int tmp;
    int mna,mnb;
    mna = *min_element(veca.begin(),veca.end());
    mnb = *min_element(vecb.begin(),vecb.end());
    mn = mna+mnb;
    tmp = mn;
    for(int i=0;i<m;i++){
        cin >> x[i] >> y[i] >> c[i];
        tmp = veca[x[i]-1]+vecb[y[i]-1]-c[i];
        if(tmp>=0) mn = min(mn,tmp);
    }
    cout << mn << endl;
}


