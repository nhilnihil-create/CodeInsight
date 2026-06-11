#include<iostream>
#include<vector>

using namespace std;

int parent(int i){return i/2;}
int left(int i){return 2*i;}
int right(int i){return 2*i+1;}

void maxHeapify(vector<int>& array,int i,int n)
{
    int left_index=left(i);
    int right_index=right(i);
    int largest=0;
    if(left_index<=n && array[left_index]>array[i])
    {
        largest=left_index;
    }
    else
    {
        largest=i;
    }
    if (right_index<=n && array[right_index]>array[largest])
    {
        largest=right_index;
    }
    if(largest!=i)
    {
        int tmp=array[largest];
        array[largest]=array[i];
        array[i]=tmp;
        maxHeapify(array,largest,n);
    }
    
}

int main()
{
    int n;
    cin>>n;
    vector<int> node(n+1,0);
    for (int i = 1; i <=n; i++)cin>>node[i];
    for (int i = n/2; i >=1; i--)maxHeapify(node,i,n);
    for (int i = 1; i <=n ; i++)
    {
        cout<<" "<<node[i];
    }
    cout<<endl;

    return 0;
}

