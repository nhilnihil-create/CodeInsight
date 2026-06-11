#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	int N;
    cin >> N;
    int c;
    int count=0;
    for(int i=1;i<=N;i++){
        cin >>  c;
        if(c!=i)count++;
    }
    if(count==0)cout << "YES" << endl;
    else if(count==2)cout << "YES" << endl;
    else cout << "NO" <<endl;

}