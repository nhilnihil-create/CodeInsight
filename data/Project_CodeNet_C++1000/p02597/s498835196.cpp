#include <bits/stdc++.h>

using namespace std;

int main(){
    char ch[200001];
  	int n, aux = 0, aux2 = 0;
  	cin >> n;
	for (int i = 0; i < n; i++)
        cin >>ch[i];
	for (int i = 0; i < n; i++)
		if(ch[i] == 'W')
            aux++;
	for (int i = n-aux; i < n; i++)
		if(ch[i] != 'W')
            aux2++;
	cout << aux2 <<endl;
	return 0;
}