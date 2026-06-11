#include<bits/stdc++.h>                                                                                                              
using namespace std;

int main(){
        long long a, b, n, mini;
        cin >> a >> b >> n;
        mini = min(b-1, n); 

        cout << ((a*mini) / b) - (a * (mini/b)) << endl;
        return 0;
}
