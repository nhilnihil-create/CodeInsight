#include <iostream>
#include <algorithm>

using namespace std;

void search_lakes(char input[], int lake_areas[],
	int *total_lake_area, int *lakes_num,
	int search_direction, int start_index, int last_index,
	char uphill_char, char flat_char, char downhill_char)
{
	int i = start_index;
	int depth = 0,
		lake_size = 0;
	bool is_inside_lake = false;

	if (search_direction == 1) {
		// start < last : i++
		for (int i = start_index; i < last_index;) {
			if (is_inside_lake)
			{
				// inside lake
				if (input[i] == uphill_char) {
					depth -= 2;
					lake_size += depth + 1;
					if (depth == 0)
					{
						// leave lake
						is_inside_lake = false;
						lake_areas[*lakes_num] = lake_size / 2;
						*total_lake_area += lake_areas[*lakes_num];
						(*lakes_num)++;
						lake_size = 0;
					}
				}
				else if (input[i] == flat_char) {
					lake_size += depth;
				}
				else if (input[i] == downhill_char) {
					lake_size += depth + 1;
					depth += 2;
				}
				i++;
			}
			else
			{
				// outside lake
				if (input[i] == uphill_char || input[i] == flat_char) {
					i++;
				}
				else if (input[i] == downhill_char) {
					// enter lake
					is_inside_lake = true;
				}
			}
		}
	}
	else
	{
		// start > last : i--
		for (int i = start_index - 1; i >= last_index;) {
			if (is_inside_lake)
			{
				// inside lake
				if (input[i] == uphill_char) {
					depth -= 2;
					lake_size += depth + 1;
					if (depth == 0)
					{
						// leave lake
						is_inside_lake = false;
						lake_areas[*lakes_num] = lake_size / 2;
						*total_lake_area += lake_areas[*lakes_num];
						(*lakes_num)++;
						lake_size = 0;
					}
				}
				else if (input[i] == flat_char) {
					lake_size += depth;
				}
				else if (input[i] == downhill_char) {
					lake_size += depth + 1;
					depth += 2;
				}
				i--;
			}
			else
			{
				// outside lake
				if (input[i] == uphill_char || input[i] == flat_char) {
					i--;
				}
				else if (input[i] == downhill_char) {
					// enter lake
					is_inside_lake = true;
				}
			}
		}
	}
}

void land_survey(char input[], int *top_index, int *last_index)
{
	int max_height = 0, now_height = 0, i = 0;
	*top_index = 0; *last_index = 0;

	for (; input[i] != '\0'; i++) {
		switch (input[i])
		{
		case '/':
			now_height++;
			if (now_height > max_height) {
				*top_index = i + 1;
				max_height = now_height;
			}
			break;
		case '\\':
			now_height--;
			break;
		case '_':
			break;
		}
	}
	*last_index = i;
}

void simulate_flood(char input[], int lake_areas[], int *total_lake_area, int *lakes_num)
{
	*total_lake_area = 0;
	*lakes_num = 0;
	int top_index, last_index, center_index;
	land_survey(input, &top_index, &last_index);

	// search 0 ==> top_index (up'/' down'\\')
	search_lakes(
		input, lake_areas, total_lake_area, lakes_num,
		1, 0, top_index, '/', '_', '\\');
	center_index = *lakes_num;
	// search last ==> top_index (up'\\' down'/')
	search_lakes(
		input, lake_areas, total_lake_area, lakes_num,
		-1, last_index, top_index, '\\', '_', '/');
	reverse(&lake_areas[center_index], &lake_areas[*lakes_num]);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int total_lake_area, lake_num;
	char input[20001];
	int lake_areas[10001];

	cin >> input;

	simulate_flood(input, lake_areas, &total_lake_area, &lake_num);

	cout << total_lake_area << endl
		<< lake_num;
	for (int i = 0; i < lake_num; i++) {
		cout << ' ' << lake_areas[i];
	}
	cout << endl;

	return 0;
}