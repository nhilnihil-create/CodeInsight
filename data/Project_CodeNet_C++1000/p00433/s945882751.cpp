#include<iostream>
using namespace std;
int i, p, sumA=0, sumB=0;
int main(){
    for (i=1; i<=4; i++) {
        cin >> p;
        sumA += p;
}
for (i=1; i<=4; i++) {
cin >> p; sumB += p;
}
cout << max(sumA, sumB) << endl;
return 0;
}