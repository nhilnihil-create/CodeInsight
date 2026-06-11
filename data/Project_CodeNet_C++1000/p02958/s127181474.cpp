#include<iostream>

void Sort(int a[], int n) 
{
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
      if (a[j] < a[min])
      min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}
int main()
{
	int n,wrong=0;
	std::cin>>n;
	int arr[n],sortedarr[n];
	for(int i=0;i<n;i++)
	{
		std::cin>>arr[i];
		sortedarr[i]=arr[i];
	}	
	Sort(sortedarr,n);
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=sortedarr[i])
			wrong++;
	}
	if(wrong<=2)
		std::cout<<"YES";
	else
		std::cout<<"NO";

	return 0;
}
