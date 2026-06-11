#include <iostream>
using namespace std;
int main(){
    int n,m,l;
    cin>>n>>m>>l;
    long int matrix1[n*m];
    long int matrix2[m*l];
    long int output[n*l]={0};

    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
            cin >> matrix1[i*m+j];
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<l;j++)
        {
            cin >> matrix2[i*l+j];
        }

     for(int i=0;i<n;i++)
         for(int j=0;j<l;j++) {
             for (int k = 0; k < m; k++)
                 output[i * l + j] += matrix1[i * m + k] * matrix2[k * l + j];
             if(j<l-1)
            cout<<output[i*l+j]<<" ";
             else
                 cout<<output[i*l+j]<<endl;
    }

    return 0;
}
