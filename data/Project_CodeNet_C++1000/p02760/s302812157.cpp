#include<bits/stdc++.h>
using namespace std; 

int main() {
    
    int x[12];
    int y[12];

    scanf("%d %d %d",&x[0],&x[1],&x[2]);
    scanf("%d %d %d",&x[3],&x[4],&x[5]);
    scanf("%d %d %d",&x[6],&x[7],&x[8]);
    
    int n;
    scanf("%d",&n);
    
	for(int i = 1 ; i <= n ; i++)
        scanf("%d",&y[i]);
    
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(x[i] == y[j])
                x[i] = 0;
        }
    }
    
    if(x[0] == x[1] && x[1] == x[2])
        cout << "Yes" << endl;
    else if(x[3] == x[4] && x[4] == x[5])
        cout << "Yes" << endl;
    else if(x[6] == x[7] && x[7] == x[8])
        cout << "Yes" << endl;
    else if(x[0] == x[4] && x[4] == x[8])
        cout << "Yes" << endl;
    else if(x[2] == x[4] && x[4] == x[6])
        cout << "Yes" << endl;
    else if(x[0] == x[3] && x[3] == x[6])
        cout << "Yes" << endl;
    else if(x[1] == x[4] && x[4] == x[7])
        cout << "Yes" << endl;
    else if(x[2] == x[5] && x[5] == x[8])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
