#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int X;  cin >> X;
    ll A, B;
    for(ll i=0; i<=200; i++){
        for(ll j=-200; j<=200; j++){
            if(pow(i,5) - pow(j,5) == X){
              	cout << i << " " << j;
              	return 0;
            }
        }
    }
}