#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(int argc, char **argv)
{
	int n ;
    cin>>n;
    
    int* vectorNum1 = new int[n];
    int* vectorNum2 = new int[n];
    
    for(int i =0;i<n;i++){
        cin>>vectorNum1[i];
    }
    
    for(int i =0;i<n;i++){
        cin>>vectorNum2[i];
    }
    
    // p = 1
    long double distance[4];
    for(int i=0;i<4;i++){
        distance[i] = 0.0;
    }
    
    for(int i =0 ;i<n;i++){
        int sum = abs(vectorNum1[i]-vectorNum2[i]);
        distance[0]+=sum;
    }
    cout.setf(ios::fixed);
    cout<<setprecision(6)<<distance[0]<<endl;
    
    // p = 2
    for(int i =0 ;i<n;i++){
        int sum = abs(vectorNum1[i]-vectorNum2[i]);
        distance[1]+= pow(sum,2);
    }
    
    
    distance[1] = sqrt(distance[1]);
    
    cout<<setprecision(6)<<distance[1]<<endl;
    
    // p = 3
    for(int i =0 ;i<n;i++){
        int sum = abs(vectorNum1[i]-vectorNum2[i]);
        distance[2]+= pow(sum,3);
    }
    
    distance[2] = cbrt(distance[2]);
    
    cout<<setprecision(6)<<distance[2]<<endl;
    
    long double max = 0;
    
    for(int i =0 ;i<n;i++){
        if(i==0){
            max = abs(vectorNum1[i]-vectorNum2[i]);
        }
        if(abs(vectorNum1[i]-vectorNum2[i])>max){
            max = abs(vectorNum1[i]-vectorNum2[i]);
        }
        
        distance[3] = max;
    }
    cout<<setprecision(6)<<distance[3]<<endl;
    
	return 0;
}