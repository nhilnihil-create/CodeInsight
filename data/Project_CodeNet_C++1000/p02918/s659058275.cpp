#include <iostream>

void swap(char& left, char& right)
{
  char temp = left;
  left = right;
  right = temp;
}

void reverse(char* arr, int begin, int end)
{
  int i = begin, k = end;
  while (i < k)
  {
    k -= 1;
    swap(arr[i], arr[k]);
    i += 1;
  }
  for (int j = begin; j < end; j += 1)
    arr[j] = (arr[j] == 'L' ? 'R' : 'L');
}

long long count_happy(char* arr, int length)
{
  long long res = 0;
  for (int i = 1; i < length; i += 1)
    if (arr[i] == arr[i - 1])
      res += 1;
  return res;
}

void print(char* queue, int n)
{
  for (int i = 0; i < n; i += 1)
    std::cout << queue[i];
  std::cout << "\n";
}

int main()
{
  int n, k;
  std::cin >> n >> k;
  char* queue = new char[n];
  for (int i = 0; i < n; i += 1)
    std::cin >> queue[i];
  
  for (int i = 1; i < n && k > 0; i += 1)
    if (queue[i] != queue[i - 1])
      for (int j = i + 1; j < n; j += 1)
        if (queue[j - 1] == queue[i] && queue[j] == queue[i - 1])
        {
          reverse(queue, i, j);
          k -= 1;
          break;
        }

  for (int i = 1; i < n && k > 0; i += 1)
    if (queue[i] != queue[i - 1])
    {
      k -= 1;
      if (queue[i - 1] == queue[0])
        reverse(queue, 0, i);
      else if (queue[i] == queue[n - 1])
        reverse(queue, i, n);
      else
        k += 1;
    }

  std::cout << count_happy(queue, n);
  delete[] queue;
  return 0;
}