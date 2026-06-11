/*
hon when the digit in the one's place of N is 2, 4, 5, 7, or 9
;
pon when the digit in the one's place of N
is 0, 1, 6 or 8
;
bon when the digit in the one's place of N
is 3.
*/

#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int n ;cin>>n;
  	map<int,string> m ;
  	m[3] = "bon";
  	m[0] =  "pon"; m[1] = "pon";m[6] = "pon";m[8] = "pon";
  	m[2] = "hon";m[4] = "hon";m[5] = "hon";m[7] = "hon";m[9] = "hon";
	cout<<m[n%10]<<endl; 

}