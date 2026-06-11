#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){
    long long S;
    cin >> S;
    //long long v = pow(10,9);
    long long t = sqrt(S);
    if(t*t == S){
        cout << "0 0 " << t <<" "<< "0 0 " << t << endl;  
        return 0;
    }
    t += 1;
    long long e = t * t - S;
    cout << "0 0 " << t << " "<< e << " "<<"1 "<<t <<endl;
    return 0;
}