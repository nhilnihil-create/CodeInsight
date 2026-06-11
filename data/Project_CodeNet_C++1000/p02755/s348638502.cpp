#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	int A,B;
    cin >> A >> B;
    int Ans=-1;
    for(int i=12;i<=1000;i++){
        int a=(i*8)/100;
        int b=(i*10)/100;
        if((a==A)&&(b==B)){
            Ans = i;
            break;
        }
    }
    cout << Ans << endl;
}