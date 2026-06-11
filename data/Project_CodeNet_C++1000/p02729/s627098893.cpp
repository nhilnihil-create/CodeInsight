#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
    cin >> n >> m;
    int count = 0;
    for(int i=n-1;i>0;i--){
      count = count+i;
    }
    for(int i=m-1;i>0;i--){
      count = count+i;
    }
    cout << count << endl;
}