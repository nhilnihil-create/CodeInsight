#include <bits/stdc++.h>
using namespace std;
int main() {
    int x,y,x1;
    int j=0;
    int N;
    cin >> x >> y;
     N=x;
     x=4*x;
    for(int i=0;i<N+1;i++){
     x1=x-2*i;
      if(x1==y){
        cout << "Yes" << endl;
        j=1;
    }
    }
    if(j!=1)cout << "No" << endl;
    return 0;
}