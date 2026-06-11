#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    while(1){
        cin>>n;
        if(n==0)break;

        double score[n];
        double sum=0;
        for(int i=0;i<n;i++){
            cin>>score[i];
            sum += score[i];
        }
        double m = sum/n;
        
        double a2=0;

        for(int i=0;i<n;i++){
            a2 += pow(score[i]-m,2);
        }
        a2 /= n;

        double a= sqrt(a2);

        printf("%8lf\n",a);

    }



    return 0;
}

