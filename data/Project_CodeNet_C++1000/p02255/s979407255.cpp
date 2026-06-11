#include <bits/stdc++.h>

using namespace std;

int arr[105];
int n;

void InsertionSort(int *arr,int n)
{
    int cost = 0;
    for(int i=1; i<n; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key)
        {
            cost++;
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
}


int main()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int t = n;
  int cost = 0;
  cout << arr[0];
  for(int i = 1; i < n; i++) {
    cout << " "<< arr[i];
  }
  cout << endl;
  for(int i=1; i<n; i++)
  {
    int key = arr[i];
    int j = i-1;
    while(j>=0 && arr[j]>key)
    {
      cost++;
      arr[j+1] = arr[j--];
      //cout << arr[j] << " ";
    }
    arr[j+1] = key;
    cout << arr[0];
    for(int k = 1; k < t; k++) {
      cout << " "<< arr[k];
    }
    cout << endl;
  }
  return 0;
}

