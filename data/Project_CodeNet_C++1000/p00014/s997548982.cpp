#include<iostream>
using namespace std;
int f(int x){
    return x*x;
}
int g(int k,int d){
    int s = f(k*d) * d;
    //cout << s <<endl;
    return s;
}
int main(){
    int n = 0;
    int d[20];
    int s[20];
    while(cin >> d[n]){
        n++;
    }
    for(int i = 0;i < n ;i++){
        s[i] = 0;
        for(int j = 1;j < 600 / d[i] ;j++ ){
            s[i] += g(j,d[i]);
        }
        cout << s[i] << endl; 
    }
    return 0;

}
