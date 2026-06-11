
#include <iostream>
#include <vector>
#include <cstdlib>
#include<set>
#include <map>
using namespace std;


   
#include <iostream>

using namespace std;
int n,m;

int main()
{
    cin >> n >> m ;
    int A[m-1];
    int sum=0;
    for (int i=0; i<m; i++) {
        cin >> A[i];
        sum += A[i];
        
    }
    if (sum > n) {
        cout << "-1" << endl;
    }else{
        cout << n-sum << endl;
    }
    
   return 0;
}
