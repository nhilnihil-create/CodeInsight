#include <bits/stdc++.h>
#include <math.h>
#define ALL(a)    a.begin(), a.end()
using namespace std;

int main() {
int A, B, C, D;cin>> A>> B >> C >> D;
int count = 1;
while(1){
if(count%2 == 1)C -= B;
else A -= D;
if(A <= 0){cout << "No";break;}
if(C <= 0){cout << "Yes";break;}
count++;


}
}