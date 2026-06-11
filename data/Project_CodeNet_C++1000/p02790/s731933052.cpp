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
void solve(){ 
	   int a,b,i;
    cin >> a >> b;
    if(a>b){
       for(i=1; i<=a; i++)
         cout << b;
    }
    else{
       for(i=1; i<=b; i++)
         cout << a;
    }
         cout << endl;
}
    
    
int main(){
    booster;
    solve();
    _terminated;
}