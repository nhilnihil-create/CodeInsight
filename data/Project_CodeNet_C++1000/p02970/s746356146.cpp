#include <bits/stdc++.h>
   
#define pb push_back
#define ll long long
#define f first
#define s second
#define ld long double
#define fa fflush(stdout); 

using namespace std;
void data() {
    #ifdef NURS
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #endif
} 
const int N = 5e5 + 100;
const ll mod = 1e9 + 7;
 
int main ()
{
	data();           
	int n, k;
	cin >> n >> k;
	k *= 2;
	k += 1;
	cout << n / k + (n % k ? 1 : 0);
}     
//JUDGE_ID: 295965SY
//Tis I