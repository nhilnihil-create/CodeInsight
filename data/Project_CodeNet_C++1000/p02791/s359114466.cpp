#include<bits/stdc++.h>

using namespace std;
#define pi acos(-1)
#define _terminated return 0
#define endl "\n"
#define yes cout << "yes" << endl 
#define no cout << "no" << endl 
#define booster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<long> > v2l;

const int mod = 1e+5;
const int mx = 2e+5;
const ll inf = 1e18;

void upper_bubble_sort(){
     int i,j,temp,number_of_input;
     int array[100];
     cin >> number_of_input;
     for(i=0; i<number_of_input; i++)
         cin >> array[i];
         for(i=0; i<number_of_input; i++){
             for(j=0; j<(number_of_input-i-1); j++){
               if(array[j] > array[j+1]){
                 temp = array[j];
                 array[j] = array[j+1];
                 array[j+1] = temp;
                }
              }
         }
    for(i=0; i<number_of_input; i++)
      cout << array[i] << endl;
}
void bst(void){
          int low,high,mid,keynum,num,array[100];
          cin >> keynum;
          low = 1;
	         high = num;
         	do{
		        mid = (low + high) / 2;
		         if(keynum < array[mid])
			         high = mid - 1;
		         else if (keynum > array[mid])
			         low = mid + 1;
	         } 
          while (keynum != array[mid] && low <= high);
	        if(keynum == array[mid]){
            cout << "number located at " << mid +1 << endl;}
         else
           no;
        }

int solvio1(int p){
     while (p >= 10) 
     p /= 10; 
     return p; 
} 
void solve(){ 
    int N,P,i; 
    int ans = INT_MAX;
    cin >> N;
    int cnt = 0;
    for(i=0; i<N; i++){ 
       cin >> P; 
       if(P <= ans){ 
          ans = P; 
          cnt++; 
       } 
     } 
    cout << cnt << endl;
}
    
int main(){
    booster;
    solve();
    _terminated;
}