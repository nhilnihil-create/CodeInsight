#include<stdio.h>
long long a[200001],b[200001];
long long x=0;
void Merge(long long A[],long long B[],int left,int mid,int right)
{
    int n1,n2;
    n1=left;
    n2=mid+1;
    int k=left;
    while(n1!=mid+1&&n2!=right+1)
    {
        if(A[n1]>A[n2])
        {
            B[k++]=A[n2++];
            x=x+mid+1-n1;
        }
        else
            B[k++]=A[n1++];
    }
    while(n1!=mid+1)
        B[k++]=A[n1++];
    while(n2!=right+1)
        B[k++]=A[n2++];
    for(int i=left;i<=right;i++)
        A[i]=B[i];
    return;
}
void MergeSort(long long A[],long long B[],int left,int right)
{
    int mid;
    if (left < right)
    {
        mid=(left + right)/2;
        MergeSort(A,B,left,mid);
        MergeSort(A,B,mid+1,right);
        Merge(A,B,left,mid,right);
    }
    return;
}
int main(){
    long long n;
    scanf("%d",&n);
    for(long long i=0;i<n;i++)
        scanf("%d",&a[i]);
    MergeSort(a,b,0,n-1);
    printf("%ld\n",x);
    return 0;
}