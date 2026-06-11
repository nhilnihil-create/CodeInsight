#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int d[k];
    int sunuke[n];
  	for(int i=0; i<n; i++){
		sunuke[i]=0;	
    }
    for(int i=0; i<k; i++){
        cin >> d[i];
        int a;
        for(int j=0; j<d[i]; j++){
            cin >> a;
            sunuke[a-1]++;   
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(sunuke[i] == 0) count++;
    }
    cout << count << endl;
    return 0;
}