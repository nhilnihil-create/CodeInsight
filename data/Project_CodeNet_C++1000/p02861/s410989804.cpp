#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int N;
    int X[8],Y[8];

    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d %d",&X[i],&Y[i]);
  
    int array[] = {0,1,2,3,4,5,6,7};

    double sum = 0;
    do{
        for(int i=0; i<N-1; i++){
            int tmp1 = array[i];
            int tmp2 = array[i+1];
            sum += hypot(X[tmp1]-X[tmp2],Y[tmp1]-Y[tmp2]);
        }
    }while(next_permutation(array,array+N));

    long long C=1;
    for(int i=1; i<=N; i++)
        C*=i;
    cout << fixed << setprecision(6) << sum / C << '\n';

    return 0;
}
