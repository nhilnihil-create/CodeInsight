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
    int n,k;
    cin >> n >> k;
    int c[n][1];
    for(int i=0;i<n;i++){
        c[i][0]=0;
    }
    int a[k][n];
    for(int i=0;i<k;i++){
        int d;
        cin >> d;
        for(int j=0;j<d;j++){
            cin >> a[i][j];
            for(int k=0;k<n;k++){
                if(k+1==a[i][j]) c[k][0]++;
            }
        }
    }
    int counter=0;
    for(int i=0;i<n;i++){
        if(c[i][0]==0) counter++;
    }
    cout << counter << endl;
}