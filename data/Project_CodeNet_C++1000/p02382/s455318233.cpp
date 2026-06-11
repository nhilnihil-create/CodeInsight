#include <iostream>
#include <cmath>
using namespace std;

double dist(int n,int x[],int y[],int p){
    double d=0;
    
    if(p!=-1){
        for(int i=0;i<n;i++){
            d += pow(abs(x[i]-y[i]),p);
        }
        d = pow(d, 1.0/p);
    }else{
        for(int i=0;i<n;i++){
            double temp = abs(x[i]-y[i]);
            if(temp > d){
                d = temp;
            }
        }
    }
    return d;
}

int main(void){
    int n;
    cin >> n;
    
    int x[n];
    int y[n];
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        cin >> y[i];
    }
    
    double d1 = dist(n,x,y,1);
    double d2 = dist(n,x,y,2);
    double d3 = dist(n,x,y,3);
    double di = dist(n,x,y,-1);
    
    cout << fixed << d1 << endl;
    cout << fixed << d2 << endl;
    cout << fixed << d3 << endl;
    cout << fixed << di << endl;

    return 0;
}