#include <iostream>
#include <algorithm>
#include <vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main() {
	int n,k=0,b;
	vector <int> L;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b;
		L.push_back(b);
	}
    int ans = 0;
    for(int i = 0; i < n - 2; i++){
        for(int j = i + 1; j < n - 1; j++){
            for(int k = j + 1; k < n; k++){
                if(L[i] != L[j] && L[j] != L[k] && L[k] != L[i]){
                    if(L[i] + L[j] > L[k] && L[j] + L[k] > L[i] && L[i] + L[k] > L[j]){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
	return 0;
}