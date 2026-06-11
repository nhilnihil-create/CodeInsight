#include<iostream>
 using namespace std;
 typedef long long int ll;
 int main(){
 ll A, V;
 cin >> A >> V;
 ll B,W;
 cin >> B >> W;
 ll T;
 cin >> T;
 ll D=abs(A-B);
 ll D2=(V-W)*T;
 puts(D<=D2?"YES":"NO");}