#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	long long int N;
    cin >> N;
    long long int Ans=0;
    for(int i=1;i<N;i++)Ans+=i;
    cout << Ans << endl;
}