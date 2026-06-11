#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    long double num=n;
    num=2/num;

    vector<int> x(n),y(n);
    for(int i=0; i<n; i++){
        cin >> x.at(i) >> y.at(i);
    }

    long double dist=0;
    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            dist+=sqrt((x.at(i)-x.at(j))*(x.at(i)-x.at(j))+(y.at(i)-y.at(j))*(y.at(i)-y.at(j)));
            //cout << dist << endl;
        }
    }
    cout << fixed << setprecision(15)<< num*dist << endl;
}