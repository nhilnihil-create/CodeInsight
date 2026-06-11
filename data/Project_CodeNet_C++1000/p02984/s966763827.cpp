#include<bits/stdc++.h>
using namespace std;
using li = long long int;

int N;
int A[100010];
int Mountain[100010];
int x1 = 0;

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){ 
      cin >> A[i];
      if(i & 1) x1 += A[i];
      else x1 -= A[i];
    }

    Mountain[1] = x1;

    li neighbour = Mountain[1] / 2;
    cout << Mountain[1] << endl;
    for(int i = 1; i <= N-1; i++){
        Mountain[i+1] = 2 * (A[i] - neighbour);
        cout << Mountain[i+1] << endl;
        neighbour = Mountain[i+1] / 2;
    }
    return 0;
}