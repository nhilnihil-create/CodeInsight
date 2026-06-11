#include <iostream>
#define Max 1000000001
using namespace std;
long long cnt;

void merge(int A[],int left,int mid,int right)
{
    int L[mid-left+1],R[right-mid+1],L_index=0,R_index=0;
    for(int i=0;i<mid-left;i++)
        L[i]=A[left+i];
    L[mid-left]=Max;
    for(int i=0;i<right-mid;i++)
        R[i]=A[mid+i];
    R[right-mid]=Max;
    for(int i=left;i<right;i++)
    {
        if(L[L_index]<=R[R_index])
        {
            A[i]=L[L_index];
            L_index++;
        }
        else{
            A[i]=R[R_index];
            R_index++;
            if(L_index!=mid-left)
                cnt+=mid-left-L_index;
        }
    }
}
void mergeSort(int A[],int left,int right)
{
    if(left+1<right)
    {
        int mid = (left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}
int main(){
    int n,A[200000];
    cin>>n;
    cnt=0;
    for(int i=0;i<n;i++)
        cin>>A[i];
    mergeSort(A,0,n);
    cout<<cnt<<endl;
    return 0;
}
