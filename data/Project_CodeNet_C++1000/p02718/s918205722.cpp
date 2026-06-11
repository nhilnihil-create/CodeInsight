#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    double a[n],sum=0;
    int counter=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum += a[i];
    }
    double boader=sum/(4*m);
    for(int i=0;i<n;i++){
        if(double(a[i])>=boader) counter++;
    }
    if(counter>=m){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}