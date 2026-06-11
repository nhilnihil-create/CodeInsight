#include<iostream>
#include<cstdio>
using namespace std;
int partition(int* arr,int left,int right){
    int x = arr[right];
    int i,j;
    for(i=left-1,j=left;j<right;j++){
        if(arr[j] <= x)
            swap(arr[j],arr[++i]);
    }
    swap(arr[i+1],arr[right]);
    return i+1;
}
int main(){
    int len;
    cin>>len;
    int* arr=new int[len];
    for(int i=0;i<len;i++)
        cin>>arr[i];
    
    int p = partition(arr,0,len-1);
    for(int i=0;i<len;i++)
        if(i){
            if(i!=p)
                cout << " " << arr[i];
            else
                printf(" [%d]",arr[i]);
        }
        else{
            if(i!=p)
                cout << arr[i];
            else
                printf("[%d]",arr[i]);
        }
    cout << endl;
    delete[]arr;
    return 0;
}

