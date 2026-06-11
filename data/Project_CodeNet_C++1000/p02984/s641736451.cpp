#include<bits/stdc++.h>
using namespace std;
using li = long long int;

int N;
li A[100010];
li Mountain[100010];
li total_vol = 0;     //the total vol of rain
li total_vol_o = 0;  //odd number's total vol

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){ 
        cin >> A[i]; 
        total_vol += A[i];
        if(i & 1) total_vol_o += A[i];
    }

    Mountain[1] = 2 * total_vol_o - total_vol;

    li neighbour = Mountain[1] / 2;
    cout << Mountain[1] << endl;
    for(int i = 1; i <= N-1; i++){
        Mountain[i+1] = 2 * (A[i] - neighbour);
        cout << Mountain[i+1] << endl;
        neighbour = Mountain[i+1] / 2;
    }
    return 0;
}