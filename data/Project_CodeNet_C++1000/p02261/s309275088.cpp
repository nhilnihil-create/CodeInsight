#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<string> BubbleSort(vector<string> vs, int n)
{
  int i, j, flag;
  for(i=1; i<n; i++)
  {
    flag = 0;
    for(j=0; j<n-i; j++)
    {
      if(vs[j][1] > vs[j+1][1])
      {
        swap(vs[j], vs[j+1]);
        flag = 1;
      }
    }
    if(flag == 0)
      break;
  }
  return vs;
}

vector<string> SelectionSort(vector<string> vs, int n)
{
  int i, j, minv;
  for(i=0; i<n-1; i++)
  {
    minv = i;
    for(j=i+1; j<n; j++)
    {
      if(vs[j][1] < vs[minv][1])
        minv = j;
    }
    swap(vs[i], vs[minv]);
  }
  return vs;
}

int pri(vector<string> vs, int n)
{
  for(int i=0; i<n; i++)
  {
    if(i)
      cout << " ";
    cout << vs[i];
  }
  cout << endl;
}

int isstable(vector<string> vsb, vector<string> vss, int n)
{
  for(int i=0; i<n; i++)
  {
    if(vsb[i] != vss[i])
    {
      printf("Not stable\n");
      return 0;
    }
  }
  printf("Stable\n");
  return 0;
}
int main()
{
  int n;
  scanf("%d", &n);
  vector<string> input, vsb, vss;
  for(int i=0; i<n; i++)
  {
    string temp;
    cin >> temp ;
    input.push_back(temp);
  }
  vsb = vss = input;
  vsb = BubbleSort(vsb, n);
  vss = SelectionSort(vss, n);
  pri(vsb, n);
  printf("Stable\n");
  pri(vss, n);
  isstable(vsb, vss, n);
  return 0;
}

