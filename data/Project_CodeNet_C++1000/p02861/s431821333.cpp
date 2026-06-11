#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void)
{
    long double sum = 0;
    long double ave = 0;
    int N;
    long double C=1;
    int tmp1, tmp2;
    int X[10],Y[10];

    scanf("%d",&N);
    
    for(int i=0; i<N; i++){
        scanf("%d %d",&X[i],&Y[i]);
    }
    
    for(int i=1; i<=N; i++){
        C*=i;
    }
    //cout << "C=" << C << endl;

    

    int array[] = {0,1,2,3,4,5,6,7};

    do{
        sum = 0;
        for(int i=0; i<N-1; i++){
            tmp1 = array[i];
            tmp2 = array[i+1];
            //cout << array[i];
            //if(i != N-1) cout << " ";
            //sum += (long double)sqrt(pow((long double)(X[tmp1]-X[tmp2]),2)+pow((long double)(Y[tmp1]-Y[tmp2]),2))/(long double)C;
            sum += hypot(X[tmp1]-X[tmp2],Y[tmp1]-Y[tmp2])/C;
            
            //cout << "sum =" <<sum << endl;
        }
        //cout << sum << endl;
        ave += (long double)sum;

    }while(next_permutation(array,array+N));

    cout << fixed << setprecision(12) << ave << endl;
    

    return 0;
}